# Data Engineering Lab 03 -- Sending Data to Airflow's Postgres Database

This is the solution to the task set in the lab -- adding data to the Postgres Database. We will review this solution next week.

```python
import datetime as dt
from datetime import timedelta

from airflow import DAG
from airflow.operators.bash_operator import BashOperator
from airflow.operators.python_operator import PythonOperator

import pandas as pd
import psycopg2

def FillDB():
    cur = None
    try:
        conn = psycopg2.connect(
            host="postgres",
            database="airflow",
            user="airflow",
            password="airflow")
        cur = conn.cursor()
        create_command = """
        CREATE TABLE people (
            ID SERIAL PRIMARY KEY,
            NAME VARCHAR(255) NOT NULL,
            AGE INTEGER NOT NULL,
            STREET VARCHAR(255) NOT NULL,
            CITY VARCHAR(50) NOT NULL,
            STATE VARCHAR(50) NOT NULL,
            ZIP INTEGER NOT NULL
        )
        """
        cur.execute(create_command)
        conn.commit()
    except(Exception):
        print("Failed to create table")
    
    try:
        insert_command = """
        INSERT INTO people(NAME, AGE, STREET, CITY, STATE, ZIP)
        VALUES(%s, %s, %s, %s, %s, %s) RETURNING ID;
        """
        df=pd.read_csv('/home/airflow/data/data.csv')
        for i,r in df.iterrows():
            id = cur.execute(insert_command, (r['name'], r['age'], r['street'], r['city'], r['state'], r['zip']))
            print("Inserted person id " + id)
        print("Database insert complete")
    except(Exception):
        print("Failed to insert data")
    conn.commit()
    cur.close()
    conn.close()
    
default_args = {
    'owner': 'Kevin Chalmers',
    'start_date': dt.datetime(2023, 2, 1),
    'retries': 1,
    'retry_delay': dt.timedelta(minutes=5),
}

with DAG(
    'database-build',
    default_args=default_args,
    schedule_interval='@once'
) as dag:
    print_starting = BashOperator(
        task_id="starting",
        bash_command='echo "Reading data"'
    )
    DBtask = PythonOperator(
        task_id='FillDB',
        python_callable=FillDB
    )
    print_starting >> DBtask
```
