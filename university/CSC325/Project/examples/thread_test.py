# Click Counter
# Demonstrates binding an event with an event handler
# Also shows thread working in background of gui application.

from tkinter import *
import threading
import time

class Application(Frame):
	def __init__(self, master):
		super(Application, self).__init__(master)
		self.grid()
		self.create_widget()
	def create_widget(self):
		self.bttn = Button(self)
		self.bttn["text"] = "Total Clicks: 0"
		self.button_clicks = 0 #Number of times the button has been clicked
		self.bttn["command"] = self.update_count
		self.bttn.grid()
	def update_count(self):
		self.button_clicks += 1
		print("Hello")
		self.bttn["text"] = "Total Clicks: " + str(self.button_clicks)

#main

root = Tk()
root.title("Click Counter")
root.geometry("200x50")

app = Application(root)

#Make Thread
def worker():
	while True:
		time.sleep(1)
		print(app.button_clicks)
t = threading.Thread(target=worker)
t.daemon = True  # thread dies when main thread (only non-daemon thread) exits.
t.start()

root.mainloop()
