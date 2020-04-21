# Imports ophalen score
import serial
from time import sleep

# Imports voor GUI
from kivy.app import App
from kivy.uix.label import Label
from kivy.uix.gridlayout import GridLayout
from kivy.graphics import Color, Rectangle
from kivy.clock import Clock

SIZE = 150

# * Serial poort en verzend snelheid constantes
ser = serial.Serial('COM3', 9600)  # ? Check Arduino voor juiste poort (COM6)

# * Scores in volgende volgorde: Rood, Wit, Blauw, groen, geel
scores = [0, 0, 0, 0, 0]
# delayT = 3  # Tijd dat applicatie 'slaapt' in SECONDEN


class BackgroundLabel(Label):
    def __init__(self, r, g, b, a, user, **kwargs):
        super(BackgroundLabel, self).__init__(**kwargs)
        self.r = r
        self.g = g
        self.b = b
        self.a = a
        self.user = user

    def on_size(self, *args):
        self.canvas.before.clear()
        with self.canvas.before:
            Color(self.r, self.g, self.b, self.a)
            Rectangle(pos=self.pos, size=self.size)

    def update(self, *args):
        self.text = str(scores[self.user])

class ScorebordApp(App):

    def timer(self, dt):
        antS = ser.readline()
        antC = float(antS.decode('ascii'))

        if (antC == 0):  # Check rood
            scores[0] += 1
            antC = 50

        elif (antC == 1):
            scores[1] += 1
            antC = 50
            #sleep(delayT)

        elif (antC == 2):
            scores[2] += 1
            antC = 50
            #sleep(delayT)

        elif (antC == 3):
            scores[3] += 1
            antC = 50
            #sleep(delayT)

        elif (antC == 4):
            scores[4] += 1
            antC = 50
            #sleep(delayT)

    def build(self):
        layout = GridLayout(rows=2)
        secondRow = GridLayout(cols=6)

        rood = BackgroundLabel(
            user=0,
            font_size=SIZE,
            r=1, g=0, b=0, a=1
        )

        groen = BackgroundLabel(
            user=3,
            font_size=SIZE,
            r=0, g=1, b=0, a=0.25
        )

        wit = BackgroundLabel(
            user=1,
            font_size=SIZE,
            color=(0, 0, 0, 1),
            r=1, g=1, b=1, a=1
        )
        blauw = BackgroundLabel(
            user=2,
            font_size=SIZE,
            r=0, g=0, b=1, a=1
        )

        geel = BackgroundLabel(
            user=4,
            font_size=SIZE,
            color=(0, 0, 0, 1),
            r=1, g=1,b=0,a=1
        )

        secondRow.add_widget(rood)
        secondRow.add_widget(wit)
        secondRow.add_widget(blauw)
        secondRow.add_widget(groen)
        secondRow.add_widget(geel)

        layout.add_widget(
            Label(text="Wolven Quiz", size_hint_y=0.25, font_size=50))
        layout.add_widget(secondRow)

        Clock.schedule_interval(rood.update, 0.5)
        Clock.schedule_interval(wit.update, 0.5)
        Clock.schedule_interval(blauw.update, 0.5)
        Clock.schedule_interval(groen.update, 0.5)
        Clock.schedule_interval(geel.update, 0.5)

        Clock.schedule_interval(self.timer, 15)

        return layout

# TODO: Check voor scalibilty functie adhv scores


ScorebordApp().run()

# Check of er juiste antwoorden gegeven zijn
# while True:
    
