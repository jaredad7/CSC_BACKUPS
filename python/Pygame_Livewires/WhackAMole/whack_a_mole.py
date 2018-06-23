"""
Whack a Mole!!!  The fun game where we abuse these poor moles who pop up everywhere!!!

<Author == JARED DEMBRUN>
<Date == 11.6.2013>

Using python3.3.1, graphical interface

"""
from livewires import games, color

games.init(screen_width = 1280, screen_height = 556, fps = 50)

field = games.load_image("green-grass.jpg", transparent = False)
games.screen.background = field

score = games.Text(value = 0, size = 20, color = color.black, x = 10, y = 10)#tracks the number of moles hit
games.screen.add(score)

games.screen.mainloop()

#end
