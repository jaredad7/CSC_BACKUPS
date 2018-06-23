from tkinter import *

class Application(Frame):
	def __init__(self, master):
		super(Application, self).__init__(master)
		self.grid()
		self.create_widget()
	def create_widget(self):
		self.b = Button(self)
		self.b["text"] = "Change"
		self.b["command"] = self.run
		self.photo = PhotoImage(file = '../stillFrames/stove.gif')
		self.label = Label(image=self.photo)
		self.label.image = self.photo
		self.b.grid(column = 0, row = 0, sticky = W)
		self.label.grid(column = 0, row = 1, sticky = W)
	def run(self):
		print("Running")
		self.photo = PhotoImage(file = '../stillFrames/grill.gif')
		self.label = Label(image=self.photo)
		self.label.image = self.photo
		self.label.grid(column = 0, row = 1, sticky = W)

root = Tk()
app = Application(root)
root.mainloop()

"""from tkinter import *
#In class
class Test:
	def __init__(self, master):
		self.photo = PhotoImage(file = '../stillFrames/stove.gif')
		self.label = Label(image=self.photo)
		self.label.image = self.photo
		self.label.pack()

root = Tk()
test = Test(root)
root.mainloop()"""
"""
import tkinter
#Out class
root = tkinter.Tk()
photo = tkinter.PhotoImage(file = '../stillFrames/stove.gif')
label = tkinter.Label(image=photo)
label.image = photo
label.pack()
root.mainloop()"""
