
# coding: utf-8

# In[11]:


import sys
import datetime
import os
import argparse
import time
import subprocess
import pandas as pd
import seaborn as sns


# In[ ]:


#parser = argparse.ArgumentParser()
#parser.add_argument('-op1', type=str , dest='op1', choices=['sp','cdl','v','rtl'] , required=True , help = "Accepted output formats : sp,v,cdl,rtl" )
#parser.add_argument('-rundir', type=str , default=os.environ["USER"]+"/netlists/" , help= "Run directory, Default is $WARD/netlists/<format>")
#args = parser.parse_args()


# In[7]:


def read_data(filename,format):
    if format == 'json':
        df=pd.read_json (filename)
    else:
        df=pd.read_csv(filename)
    df.head(5) # disaply top 5 rows
    df.describe() # Find mean, median, std deviation of each colomn
    df.info() #print data type of each column. Can also use df.dtypes()
    print("The file has", df.shape[0] , "rows and", df.shape[1] , "columns")


# In[8]:


def check_null_data(df):
    print(df.isna().sum())


# In[9]:


def get_categorical_data(df):
    cat_columns = df.select_dtypes(include='object').columns # Get all catagorical columns
    for col in cat_columns:
        print(df[col].value_counts()) # groups by a column and displays number of occurances


# In[10]:


def corr_matrix(df):
    corr_matrix = df.corr() #display correlation of each numeric folumn with one another in terms if Pearson's correlation (-1 to 1)
    plt.subplots(figsize=(10,7))
    sns.heatmap(corr_matrix, square=True, annot=True, vmax=1.0, vmin=-1.0,cmap="RdBu").set_title('Correlation Matrix')
    plt.yticks(rotation=0)
    plt.xticks(rotation=90)

