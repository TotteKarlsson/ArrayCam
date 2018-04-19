import sqlalchemy
import pandas as pd
import matplotlib.pyplot as plt
#matplotlib notebook

server='atdb.corp.alleninstitute.org'
username='admin'
password='atdb123'
database='shotgundb'
port=5432

from sqlalchemy import create_engine
conn_string = 'postgresql://{}:{}@{}:{}/{}'.format(username,password,server,port,database)
engine = create_engine(conn_string)

sensor_locations=[4,5,6]
f,ax=plt.subplots(figsize=(10,8))

for sensor_location in sensor_locations:
    df = pd.read_sql_query('select * from sensordata where location={}'.format(sensor_location),engine)
    temp_col = 'temp%d'%sensor_location
    hum_col = 'hum%d'%sensor_location
    df[temp_col]=df['data1']
    df[hum_col]=df['data2']

    df.plot(x='date_time',y=[temp_col,hum_col],ax=ax)
    plt.show()

df = pd.read_sql_query('select * from sensordata'.format(sensor_location),engine)
df.groupby('location').plot(x='date_time',y=['data1','data2'])
plt.show()