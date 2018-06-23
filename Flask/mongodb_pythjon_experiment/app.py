#An example flask app using mongodb
import os, time, datetime
from flask import Flask, render_template, request
from pymongo import MongoClient

app = Flask(__name__)

client = MongoClient()
db = client.test


@app.route('/')
def index():
    return render_template('home.html', saved=False)

@app.route('/save', methods=['POST'])
def save():
	#Save to database with timestamp
	date = str(datetime.datetime.fromtimestamp(time.time()).strftime('%Y-%m-%d %H:%M:%S'))
	data = request.form["data"]
	result = db.restaurants.insert_one({ "timestamp":date, "data":data })
	print "Saved: " + data + ", ObjectID = " + str(result.inserted_id)
	return render_template('home.html', saved=True)

@app.route('/display_data')
def display_data():
	cursor = db.restaurants.find()
	data = list()
	for datum in cursor:
		data.append(datum)
	return render_template('display_data.html', data=data)

if __name__ == '__main__':
    app.run()