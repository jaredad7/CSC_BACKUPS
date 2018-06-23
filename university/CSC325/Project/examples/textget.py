#Print out what we got from the text box.
from tkinter import *

class Application(Frame):
	def __init__(self, master):
		super(Application, self).__init__(master)
		self.grid()
		self.create_widget()
	def create_widget(self):
		self.bttn = Button(self)
		self.bttn["text"] = "Get"
		self.bttn["command"] = self.update
		self.text = Text()
		self.bttn.grid(column=0,row=0,sticky=E)
		self.text.grid(column=0,row=1)
	def update(self):
		print(self.text.get("1.0", 'end-1c'))

#main

root = Tk()
root.title("Click Counter")
root.geometry("500x50")

app = Application(root)

root.mainloop()

