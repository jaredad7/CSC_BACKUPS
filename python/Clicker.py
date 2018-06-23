# Click Counter
# Demonstrates binding an event with an event handler

from tkinter import *

class Application(Frame):
    def __init__(self, master):
        super(Application, self).__init__(master)
        self.grid()
        self.button_clicks = 0 #Number of times the button has been clicked
        self.create_widget()
    def create_widget(self):
        self.bttn = Button(self)
        self.bttn["text"] = "Total Clicks: 0"
        self.bttn["command"] = self.update_count
        self.bttn.grid()
    def update_count(self):
        self.button_clicks += 1
        self.bttn["text"] = "Total Clicks: " + str(self.button_clicks)

#main

root = Tk()
root.title("Click Counter")
root.geometry("200x50")

app = Application(root)

root.mainloop()
