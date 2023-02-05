from datetime import datetime, timedelta
from textwrap import dedent

from airflow import DAG

from airflow.operators.bash import BashOperator
with DAG(
    "tutorial",
    default_args={
        "depends_on_past": False,
        "email": ["kevin@kevin.com"],
        "email_on_failure": False,
        "email_on_rety": False,
        "retries": 1,
        "retry_delay": timedelta(minutes=5),
    },
    description="A simple tutorial DAG",
    schedule=timedelta(days=1),
    start_date=datetime(2023, 2, 1),
    catchup=False,
    tags=["example"],
) as dag:
    t1 = BashOperator(
        task_id="print_date",
        bash_command="date"
    )
    t2 = BashOperator(
        task_id="sleep",
        depends_on_past=False,
        bash_command="sleep 5",
        retries=3,
    )
    templated_command = dedent(
        """
        {% for i in range(5) %}
            echo "{{ ds }}"
            echo "{{ macros.ds_add(ds, 7)}}"
        {% endfor %}
        """
    )
    t3 = BashOperator(
        task_id="templated",
        depends_on_past=False,
        bash_command=templated_command
    )
    
    t1 >> [t2, t3]