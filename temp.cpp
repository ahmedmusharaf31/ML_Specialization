#include<bits/stdc++.h>

void solve(){
    int n,m,k; cin>>n>>m>>k;

    int var=(k%2==0)?(k/2):((k/2)+1);
    char c=(k%2==0)?'R':'L';

    int temp=var;
    while(temp>=0){
        temp-=m;
    }
    temp+=m;
    int n1,m1;
    m1=((temp==0)?m:temp);
    n1=((var%m)?(var/m)+1:(var/m));
    cout<<n1<<" "<<m1<<" "<<c;

}

int main(){
    //    tst
    {
        solve();nl;
    }
}
/*
lab 07
import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.tree import DecisionTreeClassifier
from sklearn.metrics import classification_report, accuracy_score
import seaborn as sns

df = sns.load_dataset("titanic")

df.head(3)

df2 = df.drop(columns=["deck", "adult_male", "alive", "alone"], inplace=False)
df2.head(3)

df2.info()

from sklearn.preprocessing import LabelEncoder

for i in df2.columns:
    if df2[i].dtype == "object":
        df2[i] = LabelEncoder().fit_transform(df2[i])

df2.head(3)

for i in df2.columns:
    if df2[i].dtype == "category":
        df2[i] = LabelEncoder().fit_transform(df2[i])

df2.head(3)

# Fill missing values with column mean
for i in df2.columns:
    if df2[i].dtype == "float64":
      df2[i] = df2[i].fillna(df2[i].mean())

df2.info()

# Split into features (X) and target (y)
X = df2.drop(columns=["survived"])
y = df2["survived"]

# OR

# X = df[df.columns[1:]]  # All columns except 'Survived'
# y = df['Survived']  # Target variable

# Train-test split
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

X_train.shape, X_test.shape, y_train.shape, y_test.shape

dt = DecisionTreeClassifier()
dt.fit(X_train, y_train)

y_pred = dt.predict(X_test)

y_pred

y_pred.shape

from sklearn.metrics import confusion_matrix
conf = confusion_matrix(y_test, y_pred)
print(conf)

# Visualizing confusion matrix using seaborn
import seaborn as sns
import matplotlib.pyplot as plt

sns.heatmap(confusion_matrix(y_test, y_pred), annot=True, lw=2, cbar=False)
plt.ylabel("True Values")
plt.xlabel("Predicted Values")
plt.title("CONFUSION MATRIX VISUALIZATION")
plt.show()

from sklearn.metrics import accuracy_score, classification_report, f1_score, recall_score, precision_score

# Calculate Accuracy
acc = accuracy_score(y_test, y_pred)
print("Accuracy:", acc)

# Generate Classification Report
res = classification_report(y_test, y_pred)
print(res)

# Calculate F1-score
# f1 = f1_score(y_test, y_pred)
# print(f1)

# # Calculate Recall Score
# recall = recall_score(y_test, y_pred)
# print(recall)

# # Calculate Precision Score
# precision = precision_score(y_test, y_pred)
# print(precision)
*/

/*
lab 08

import pandas as pd
import numpy as np
from sklearn.linear_model import LinearRegression
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import OneHotEncoder
from sklearn.compose import ColumnTransformer
from sklearn.metrics import mean_squared_error, r2_score, mean_absolute_error, mean_absolute_percentage_error

salary = pd.read_csv('https://github.com/ybifoundation/Dataset/raw/main/Salary%20Data.csv')

salary.info()

salary.columns

X = salary['Experience Years']
y = salary['Salary']

X_train, X_test, y_train, y_test = train_test_split(X,y, train_size=0.7, random_state=2529)

X_train.shape, X_test.shape, y_train.shape, y_test.shape

lr = LinearRegression()

X_train = pd.DataFrame(X_train)

X_train.shape

lr.fit(X_train, y_train)

lr.intercept_

lr.coef_

----------------------------
import pandas as pd
import numpy as np
from sklearn.linear_model import LinearRegression
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import OneHotEncoder
from sklearn.compose import ColumnTransformer
from sklearn.metrics import mean_absolute_error, mean_absolute_percentage_error, mean_squared_error

house = pd.read_csv('https://github.com/YBIFoundation/Dataset/raw/main/Boston.csv')

house.head()

house.info()

house.describe()

house.columns

y = house['MEDV']

X = house.drop(['MEDV'],axis=1)

from sklearn.model_selection import train_test_split
X_train, X_test, y_train, y_test = train_test_split(X,y, train_size=0.7, random_state=2529)

X_train.shape, X_test.shape, y_train.shape, y_test.shape

#initialize the model
model = LinearRegression()

#train or fit model
model.fit(X_train,y_train)

model.intercept_

model.coef_

#make the model make predictions
y_pred = model.predict(X_test)

y_pred

mean_absolute_error(y_test,y_pred)

mean_absolute_percentage_error(y_test,y_pred)

mean_squared_error(y_test,y_pred)

*/

/*
lab 09
import pandas as pd
import numpy as np

from sklearn import preprocessing
from sklearn.metrics import confusion_matrix, accuracy_score
from sklearn import svm

# libraries to plot the charts
import matplotlib.pyplot as plt
import matplotlib.mlab as mlab
import seaborn as sns

df = pd.read_csv("UniversalBank.csv")

df.head()

df.describe()

import matplotlib.pyplot as plt
import seaborn as sns

df['Personal Loan'].value_counts()

from imblearn.under_sampling import RandomUnderSampler
import pandas as pd

# splitting the features and target variable
X = df.drop('Personal Loan', axis=1)
y = df['Personal Loan']


# undersampling (reducing the size of) the majority class
rus = RandomUnderSampler(random_state=42)
X_resampled, y_resampled = rus.fit_resample(X, y)

# creating a new balanced dataframe
df_resampled = pd.concat([pd.DataFrame(X_resampled, columns=X.columns),
                          pd.Series(y_resampled, name='Personal Loan')], axis=1)

# checking the balanced class distribution
print("Balanced Class Distribution:")
print(df_resampled['Personal Loan'].value_counts())


from imblearn.over_sampling import RandomOverSampler

ros = RandomOverSampler(random_state=42)
X_resampled_o, y_resampled_o = ros.fit_resample(X, y)

df_resampled_o = pd.concat([
    pd.DataFrame(X_resampled_o, columns=X.columns),
    pd.Series(y_resampled_o, name='Personal Loan')
], axis=1)

print("Balanced Class Distribution After Oversampling:")
print(df_resampled_o['Personal Loan'].value_counts())


X = df_resampled.drop('Personal Loan', axis=1)
y = df_resampled['Personal Loan']


from sklearn.model_selection import train_test_split
from sklearn.svm import SVC
from sklearn.metrics import classification_report, confusion_matrix
# from sklearn.metrics import roc_curve, auc


# splitting the datasets
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

X_train.shape, X_test.shape, y_train.shape, y_test.shape

# create an SVM model
svm_model = SVC(kernel='linear', random_state=42)

# train the model
svm_model.fit(X_train, y_train)

# make predictions on the test set
y_pred = svm_model.predict(X_test)

y_pred

sns.heatmap(confusion_matrix(y_test, y_pred), annot=True, lw=2, cmap='Blues', fmt='d')
plt.ylabel("True Values")
plt.xlabel("Predicted Values")
plt.title("CONFUSION MATRIX")
plt.show()

print("Classification Report:")
print("")
print(classification_report(y_test, y_pred))

from sklearn.preprocessing import StandardScaler
from sklearn.neighbors import KNeighborsClassifier

df2 = pd.read_csv("diabetes.csv")

df2.head()

df2['Outcome'].value_counts()

X = df2.drop('Outcome', axis=1)
y = df2['Outcome']

X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

scaler = StandardScaler()
X_train = scaler.fit_transform(X_train)
X_test = scaler.transform(X_test)

# Initialize KNN with k=3 (or any value you want to experiment with)
knn = KNeighborsClassifier(n_neighbors=3)

# Train the model
knn.fit(X_train, y_train)

# Predict on test set
y_pred = knn.predict(X_test)

print("Confusion Matrix:\n", confusion_matrix(y_test, y_pred))
print("\nClassification Report:\n", classification_report(y_test, y_pred))
print("\nAccuracy Score:", accuracy_score(y_test, y_pred))


cm = confusion_matrix(y_test, y_pred)

plt.figure(figsize=(5,4))
sns.heatmap(cm, annot=True, fmt="d", cmap="Blues")
plt.title("Confusion Matrix - KNN")
plt.xlabel("Predicted")
plt.ylabel("Actual")
plt.show()


error_rate = []

# Try different k values from 1 to 10
for k in range(1, 11):
    knn = KNeighborsClassifier(n_neighbors=k)
    knn.fit(X_train, y_train)
    pred_k = knn.predict(X_test)
    error_rate.append(np.mean(pred_k != y_test))

plt.figure(figsize=(8,6))
plt.plot(range(1, 11), error_rate, marker='o', linestyle='--', color='b')
plt.title('Error Rate vs. K Value')
plt.xlabel('K')
plt.ylabel('Error Rate')
plt.xticks(range(1, 11))
plt.show()

*/

/*
lab 10

!pip install pycaret

# load the dataset
from pycaret.datasets import get_data
df = get_data('diabetes')

# AutoML in 3 lines
from pycaret.classification import *
clf = setup(data=df, target='Class variable', session_id=123)
best_model = compare_models()

plot_model(best_model, plot='feature')

evaluate_model(best_model)

!pip install lazypredict

from lazypredict.Supervised import LazyClassifier
from sklearn.datasets import load_breast_cancer
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
import pandas as pd

data = load_breast_cancer()
X = pd.DataFrame(data.data, columns=data.feature_names)
y = data.target

X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

scaler = StandardScaler()
X_train = scaler.fit_transform(X_train)
X_test = scaler.transform(X_test)

clf = LazyClassifier(verbose=0, ignore_warnings=True, custom_metric=None)
models, predictions = clf.fit(X_train, X_test, y_train, y_test)

print(models.head(10))  # Top 10 models

*/

/*
lab 11

import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns

df = pd.read_csv('Mall_Customers.csv')

df.head()

df.info()

X = df[['Annual Income (k$)', 'Spending Score (1-100)']]

X.head()

from sklearn.preprocessing import StandardScaler
from sklearn.cluster import KMeans

scaler = StandardScaler()
X_scaled = scaler.fit_transform(X)

wcss = []  # a list to store WCSS (within cluster sum of squares) values for each k

for k in range(1, 11):
    kmeans = KMeans(n_clusters=k, random_state=42)
    kmeans.fit(X_scaled)
    wcss.append(kmeans.inertia_)

plt.plot(range(1, 11), wcss, marker='o')
plt.title('Elbow Method - Optimal K')
plt.xlabel('Number of Clusters (k)')
plt.ylabel('WCSS')
plt.show()

kmeans = KMeans(n_clusters=5, random_state=42)
cluster_labels = kmeans.fit_predict(X_scaled)

df['Cluster'] = cluster_labels

plt.figure(figsize=(8, 5))
sns.scatterplot(x=X_scaled[:, 0], y=X_scaled[:, 1], hue=df['Cluster'], palette='Set1')
plt.title('K-Means Clustering - Customer Segments')
plt.xlabel('Annual Income (scaled)')
plt.ylabel('Spending Score (scaled)')
plt.show()

!pip install scikit-learn-extra

!pip install numpy==1.23.5
!pip install scikit-learn-extra

from sklearn_extra.cluster import KMedoids

kmedians = KMedoids(n_clusters=5, metric='manhattan', random_state=42, method='pam')
cluster_labels = kmedians.fit_predict(X_scaled)

df['KMedian_Cluster'] = cluster_labels

#visualization
plt.figure(figsize=(8, 5))
sns.scatterplot(x=X_scaled[:, 0], y=X_scaled[:, 1], hue=df['KMedian_Cluster'], palette='Set2')
plt.title('K-Median Clustering - Customer Segments')
plt.xlabel('Annual Income (scaled)')
plt.ylabel('Spending Score (scaled)')
plt.show()


# using scipy
from scipy.cluster.hierarchy import dendrogram, linkage, fcluster

# method='ward' is used to minimize variance within clusters
linked = linkage(X_scaled, method='ward')

plt.figure(figsize=(10, 6))
dendrogram(linked)
plt.title('Hierarchical Clustering Dendrogram')
plt.xlabel('Data Points')
plt.ylabel('Distance')
plt.show()

cluster_labels = fcluster(linked, 5, criterion='maxclust')

df['Hierarchical_Cluster'] = cluster_labels

# using sklearn

from sklearn.cluster import AgglomerativeClustering
import matplotlib.pyplot as plt
import seaborn as sns
import pandas as pd

agglo = AgglomerativeClustering(n_clusters=5, linkage='ward')
cluster_labels = agglo.fit_predict(X_scaled)

df['Agglo_Cluster'] = cluster_labels

# viz
plt.figure(figsize=(8, 5))
sns.scatterplot(x=X_scaled[:, 0], y=X_scaled[:, 1], hue=df['Agglo_Cluster'], palette='Set2')
plt.title('Agglomerative Clustering with 5 Clusters')
plt.xlabel('Annual Income (scaled)')
plt.ylabel('Spending Score (scaled)')
plt.show()


def divisive_clustering(data, depth=0, max_depth=2):
    """
    Recursively splits data using KMeans with k=2 until max_depth is reached.
    """
    if depth == max_depth or len(data) <= 2:
        return [data]

    kmeans = KMeans(n_clusters=2, random_state=42)
    labels = kmeans.fit_predict(data)

    left_cluster = data[labels == 0]
    right_cluster = data[labels == 1]

    clusters = []
    clusters += divisive_clustering(left_cluster, depth+1, max_depth)
    clusters += divisive_clustering(right_cluster, depth+1, max_depth)

    return clusters


clusters = divisive_clustering(X_scaled, max_depth=2)

# visualizing the clusters
colors = ['red', 'blue', 'green', 'orange', 'purple', 'brown']


plt.figure(figsize=(8, 5))
for i, cluster in enumerate(clusters):
    plt.scatter(cluster[:, 0], cluster[:, 1], label=f'Cluster {i+1}', color=colors[i])

plt.title('Divisive Clustering (Top-Down)')
plt.xlabel('Annual Income (scaled)')
plt.ylabel('Spending Score (scaled)')
plt.legend()
plt.show()

*/
