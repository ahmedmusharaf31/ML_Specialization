% Read, convert & preprocess
I_color = imread('pears.png');
I       = rgb2gray(I_color);
I       = im2double(I);
I       = imadjust(I);
figure; imshow(I); title('Preprocessed Image');

% 1) Gaussian smoothing
sigma       = 1.5;
kernel_size = 2 * ceil(3*sigma) + 1;
G           = fspecial('gaussian', [kernel_size kernel_size], sigma);
I_smooth    = imfilter(I, G, 'replicate');

% 2) Compute gradient magnitude & direction
[Gx, Gy] = gradient(I_smooth);
Gmag     = hypot(Gx, Gy);
Gdir     = atan2d(Gy, Gx);      % in degrees

% 3) Non-maximum suppression
Gdir_q = mod(round(Gdir/45)*45, 180);
[rows, cols] = size(Gmag);
G_thin = zeros(rows, cols);
for i = 2:rows-1
    for j = 2:cols-1
        angle = Gdir_q(i,j);
        switch angle
            case {0, 180}
                neigh = [Gmag(i, j-1), Gmag(i, j+1)];
            case 45
                neigh = [Gmag(i-1, j+1), Gmag(i+1, j-1)];
            case 90
                neigh = [Gmag(i-1, j),   Gmag(i+1, j)];
            case 135
                neigh = [Gmag(i-1, j-1), Gmag(i+1, j+1)];
        end
        if Gmag(i,j) >= max(neigh)
            G_thin(i,j) = Gmag(i,j);
        end
    end
end

% 4) Double threshold & edge tracking by hysteresis
T_low  = 0.10;
T_high = 0.20;
BW_strong = G_thin >= T_high;
BW_weak   = (G_thin >= T_low) & (G_thin < T_high);
BW_edges  = imreconstruct(BW_strong, BW_strong | BW_weak);
figure; imshow(BW_edges); title('Canny Edges (Manual)');

% 5) MATLAB’s built-in Canny for comparison
BW_canny = edge(I, 'canny', [T_low, T_high], sigma);
figure; imshow(BW_canny); title('Canny Edges (MATLAB)');

% 6) Sweep over σ
sigma_vals = [1, 2, 3];
figure;
for k = 1:numel(sigma_vals)
    BW = edge(I, 'canny', [], sigma_vals(k));
    subplot(1,3,k), imshow(BW);
    title(['σ = ' num2str(sigma_vals(k))]);
end

% 7) Sweep over thresholds
threshold_ratios = [0.05 0.15; 0.10 0.20; 0.20 0.30];
figure;
for k = 1:size(threshold_ratios,1)
    thr = threshold_ratios(k,:);
    BW  = edge(I, 'canny', thr, sigma);
    subplot(1,3,k), imshow(BW);
    title(['T = [' num2str(thr(1)) ', ' num2str(thr(2)) ']']);
end

% 8) Hough-based line detection
[H, theta, rho] = hough(BW_canny);
peaks = houghpeaks(H, 10, 'Threshold', 0.3*max(H(:)));
lines = houghlines(BW_canny, theta, rho, peaks, ...
                   'FillGap', 10, 'MinLength', 20);

figure; imshow(I_color); hold on;
for k = 1:length(lines)
    xy = [lines(k).point1; lines(k).point2];
    plot(xy(:,1), xy(:,2), 'r', 'LineWidth', 1.5);
end
title('Lines Detected from Canny Edges');
hold off;
