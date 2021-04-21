#%%

import pandas as pd
import requests
from bs4 import BeautifulSoup
import time
import random
url = 'https://movie.douban.com/top250'
params = {'start': 0}
header = {
    'User-Agent': 'Mozilla/5.0 (Macintosh; Intel Mac OS X 11_2_3) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/89.0.4389.128 Safari/537.36'}
proxies = {
    "http": "http://220.174.236.211",
    "https": "http://220.174.236.211",
}

import pymysql
import numpy as np
create="""create database douban"""
create_table="""create table data
(
    name     varchar(1000) null,
    url      varchar(1000) null,
    number   varchar(1000) null,
    time     varchar(1000) null,
    score    varchar(50)   null,
    genre    varchar(1000) null,
    Director varchar(1000) null,
    actor    varchar(1000) null,
    place    varchar(1000) null,
    summary  varchar(1000) null
)
    charset = utf8;
"""
use="""use douban"""

class spider:
    def __init__(self):
        self.respone = None
        self.all_url = []
        self.all_name = []
        self.actor = []
        self.times = []
        self.genre = []
        self.place = []
        self.number = []
        self.score = []
        self.Director = []
        self.summary=[]
        self.result=[]
    def start(self):
        def get_url():
            try:
                respond = requests.get(url=url, headers=header, params=params)
                if respond.status_code == 200:
                    return respond
                return None
            except:
                return None

        def get_info(responds):
            try:
                result = BeautifulSoup(responds.content, features='lxml')
            except:
                print("error")
                return
            for i in result.find_all(name='div', attrs={'class': 'info'}):
                self.all_url.append(i.div.a['href'])
                self.all_name.append(i.div.a.span.text)

        def get_detail(urls):
            actor = []
            times = []
            genre = []
            place = []
            number = []
            score = []
            Director = []
            # summary=[]
            aa=','
            ditials = requests.get(urls, headers=header)
            try:
                ditial_text = BeautifulSoup(ditials.content, features='lxml')
            except:
                print("error")
                return
            for i in ditial_text.find_all(name='a', attrs={'rel': 'v:starring'}):
                actor.append(i.text)
            self.actor.append(aa.join(actor))
            for i in ditial_text.find_all(name='a', attrs={'rel': 'v:directedBy'}):
                Director.append(i.text)
            self.Director.append(aa.join(Director))
            for i in ditial_text.find_all(name='span', attrs={'property': "v:initialReleaseDate"}):
                place.append(i.text)
            self.place.append(aa.join(place))
            for i in ditial_text.find_all(name='span', attrs={'property': 'v:runtime'}):
                times.append(i.text)
            self.times.append(aa.join(times))
            for i in ditial_text.find_all(name='span',attrs={'property':'v:summary'}):
                self.summary.append(''.join(i.get_text().split()))
            for i in ditial_text.find_all(name='span', attrs={'property': 'v:genre'}):
                genre.append(i.text)
            self.genre.append(aa.join(genre))
            for i in ditial_text.find_all(name='span', attrs={'property': 'v:votes'}):
                number.append(i.text)
            self.number.append(aa.join(number))
            for i in ditial_text.find_all(name='strong', attrs={'property': 'v:average'}):
                score.append(i.text)
            self.score.append(aa.join(score))
        count=1
        for i in range(10):
            self.respone = get_url()
            time.sleep(random.randint(1,10))
            params['start'] += 25
            get_info(self.respone)
        print(len(self.all_url))
        for u in self.all_url:
            time.sleep(random.randint(2,3))
            # print(count)
            # count+=1
            get_detail(u)
        print(len(self.actor))
        self.result=pd.DataFrame()
        self.result['name']=self.all_name
        self.result['url']=self.all_url
        self.result['score']=self.score
        self.result['number']=self.number
        self.result['genre']=self.genre
        self.result['actor']=self.actor
        self.result['Dic']=self.Director
        self.result['time']=self.times
        self.result['place']=self.place
        self.result['summary']=self.summary
        database=pymysql.connect(port=3306,user="root",password="root",charset="utf8")
        cursor=database.cursor()
        try:
            cursor.execute(create)
            cursor.execute(use)
            cursor.execute(create_table)
            cursor.close()
        except:
            print("Create Error")
            return 0
        answer=np.array(self.result)
        answer=answer.tolist()
        for i in answer:
            try:
                db=pymysql.connect(port=3306,user="root",password="root",charset="utf8")
                cursor=db.cursor()
                sql="""INSERT INTO data (name,url,score,number,genre,actor,Director,time,place,summary)
                             VALUES (%s,%s,%s,%s,%s,%s,%s,%s,%s,%s)"""
                cursor.execute(use)
                cursor.execute(sql,i)
                db.commit()
                cursor.close()
            except:
                print("insert fail")
                return 0
        return 1
if __name__ == '__main__':
    Spider=spider()
    Spider.start()

