#Project for class CSC325 at Louisiana Tech. Fall 2014
#Author: Jared A Dembrun

from tkinter import *
import pickle
import threading
import time

class Application(Frame):
	def __init__(self, master):
		super(Application, self).__init__(master)
		self.grid()
		self.create_widgets()
	def create_widgets(self):
		#Text Boxes
		self.title = Entry(self)
		self.ingredients = Text(self)
		self.directions = Text(self)
		#Labels
		self.iLabel = Label(self)
		self.dLabel = Label(self)
		self.iLabel["text"] = "Ingredients"
		self.dLabel["text"] = "Directions"
		#Load Dictionary
		self.book = dict(pickle.load(open("book.dat","rb")))
		#Buttons
		self.searchTitle = Button(self)
		self.searchTitle["text"] = "Search Recipes"
		self.searchTitle["command"] = self.searchfunc
		self.save = Button(self)
		self.save["text"] = "Save Recipe"
		self.save["command"] = self.savefunc
		self.delete = Button(self)
		self.delete["text"] = "Delete Recipe"
		self.delete["command"] = self.deletefunc
		#Set up animations
		self.photo = PhotoImage(file = 'stillFrames/season.gif')
		self.label = Label(image=self.photo)
		self.label.image = self.photo
		#A list of keywords
		self.keywords = ["Mix","mix","Stir","stir","Whisk","whisk","Bake","bake","Grill","Grill","Char-grill","char-grill",
		"Chop","chop","Slice","slice","Boil","boil","Stew","stew","Season","season"]
		self.threadlist = []
		#Pack Frame
		self.title.grid(column = 0, row = 0, sticky = "N")
		self.iLabel.grid(column = 0, row = 1, sticky = "S")
		self.dLabel.grid(column = 1, row = 1, sticky = "S")
		self.ingredients.grid(column = 0, row = 2)
		self.directions.grid(column = 1, row = 2)
		self.searchTitle.grid(column = 0, row = 0, sticky = "W")
		self.save.grid(column = 0, row = 0, sticky = "E")
		self.delete.grid(column = 0, row = 3, sticky = "W")
		self.load()
	def load(self):
		self.title.insert(0,'Usage')
		self.searchfunc()
	def savefunc(self):
		if not(self.title.get() == 'Usage' or self.title.get() == 'List' or self.title.get() == 'Recipe Deleted!'):
			self.book[str(self.title.get())] = [str(self.ingredients.get("1.0",'end-1c')), str(self.directions.get("1.0",'end-1c'))]
			pickle.dump(self.book, open("book.dat", "wb"))
		#Call function to set up things for thread to use.
		self.make_list()
	def searchfunc(self):
		if self.title.get() in self.book.keys():
			self.ingredients.delete("1.0", END)
			self.directions.delete("1.0", END)
			self.ingredients.insert("1.0", str(self.book[self.title.get()][0]))
			self.directions.insert("1.0", str(self.book[self.title.get()][1]))
		elif self.title.get() == "List":
			self.ingredients.delete("1.0", END)
			self.ingredients.insert("1.0", list(self.book.keys()))
			self.directions.delete("1.0", END)
		else:
			self.ingredients.delete("1.0", END)
			self.directions.delete("1.0", END)
			self.ingredients.insert("1.0", "No such recipe.")
			self.directions.insert("1.0", "No such recipe.")
		#Call function to set up things for thread to use.
		self.make_list()
	def deletefunc(self):
		if not(self.title.get() == 'Usage' or self.title.get() == 'List' or self.title.get() == 'Recipe Deleted!'):
			del self.book[self.title.get()]
			self.title.delete(0, END)
			self.title.insert(0,'Recipe Deleted!')
			self.ingredients.delete("1.0", END)
			self.directions.delete("1.0", END)
			pickle.dump(self.book, open("book.dat", "wb"))
			self.make_list()
	def make_list(self):
		self.threadlist = self.listAnd(str(self.directions.get("1.0",'end-1c')).split(' '), self.keywords)
	#Intersect two lists, preserving the order of the original list
	def listAnd(self, inset, keyset):
		out = []
		for x in range(len(inset)):
			if inset[x] in keyset:
				out.append(inset[x])
		return out
	def animate(self):
		while True:
			#Save the length
			r = len(self.threadlist)
			if(r == 0):
				self.photo = PhotoImage(file = 'stillFrames/blank.gif')
				self.label.config(image=self.photo)
				self.label.image = self.photo
				self.label.grid(column = 0, row = 2, sticky = "N")
			for x in range(len(self.threadlist)):
				#Restart if there is a change
				if not(len(self.threadlist) == r):
					break
				#Otherwise, run normally
				else:
					#Select the proper image based on the curent word(s) and display it.
					#This will create an animation dynamically based on the supplied instructions.
					if(self.threadlist[x] == 'Mix' or self.threadlist[x] == 'mix' or
					self.threadlist[x] == 'Stir' or self.threadlist[x] == 'stir' or
					self.threadlist[x] == 'Whisk' or self.threadlist[x] == 'whisk'):
						self.photo = PhotoImage(file = 'stillFrames/mix.gif')
						self.label.config(image=self.photo)
						self.label.image = self.photo
						self.label.grid(column = 0, row = 2, sticky = "N")
					elif(self.threadlist[x] == 'Bake' or self.threadlist[x] == 'bake'):
						self.photo = PhotoImage(file = 'stillFrames/oven.gif')
						self.label.config(image=self.photo)
						self.label.image = self.photo
						self.label.grid(column = 0, row = 2, sticky = "N")
					elif(self.threadlist[x] == 'Grill' or self.threadlist[x] == 'grill' or
					self.threadlist[x] == 'Char-grill' or self.threadlist[x] == 'chargrill'):
						self.photo = PhotoImage(file = 'stillFrames/grill.gif')
						self.label.config(image=self.photo)
						self.label.image = self.photo
						self.label.grid(column = 0, row = 2, sticky = "N")
					elif(self.threadlist[x] == 'Chop' or self.threadlist[x] == 'chop' or
					self.threadlist[x] == 'Slice' or self.threadlist[x] == 'slice'):
						self.photo = PhotoImage(file = 'stillFrames/chop.gif')
						self.label.config(image=self.photo)
						self.label.image = self.photo
						self.label.grid(column = 0, row = 2, sticky = "N")
					elif(self.threadlist[x] == 'Boil' or self.threadlist[x] == 'boil' or
					self.threadlist[x] == 'Stew' or self.threadlist[x] == 'stew'):
						self.photo = PhotoImage(file = 'stillFrames/stove.gif')
						self.label.config(image=self.photo)
						self.label.image = self.photo
						self.label.grid(column = 0, row = 2, sticky = "N")
					elif(self.threadlist[x] == 'Season' or self.threadlist[x] == 'season'):
						self.photo = PhotoImage(file = 'stillFrames/season.gif')
						self.label.config(image=self.photo)
						self.label.image = self.photo
						self.label.grid(column = 0, row = 2, sticky = "N")
				time.sleep(1)

#main

root = Tk()
root.title("Electronic Cookbook")
root.geometry("1135x700")

app = Application(root)

#Make Thread
t = threading.Thread(target=app.animate)
t.daemon = True  # thread dies when main thread (only non-daemon thread) exits.
t.start()

root.mainloop()
