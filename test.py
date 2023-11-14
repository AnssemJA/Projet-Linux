from tkinter import *
import subprocess
from test import*

f1=1
f11=1
def socket():
    
    subprocess.call(["make"])
    
def clfifo():
    result=subprocess.run([subprocess.call(["make"])],stdout=subprocess.PIPE,text=True)
    #subprocess.call["./ser"]
    return result.stdout
def serfifo():
    console=subprocess.run(["./ser"],stdout=subprocess.PIPE,text=True)
    return console.stdout
def signaux():
    
    subprocess.call(["make"])
def closef1():
    global f1
    f1.destroy()


def fifo():
    global f11
    
    f2= Tk()
    f2.title("Acceuil")
    f2.geometry("1000x500")
    f2.configure(bg = "#ffffff")
    canvas = Canvas(
        f2,
        bg = "#ffffff",
        height = 500,
        width = 1000,
        bd = 0,
        highlightthickness = 0,
        relief = "ridge")
    canvas.place(x = 0, y = 0)

    background_img = PhotoImage(file = f"background.png")
    background = canvas.create_image(
        500, 260,
        image=background_img)
    result=clfifo
    canvas.create_text(400, 200, text=result, fill="black", font=('Helvetica 15 bold'))
    canvas.pack()
    f2.resizable(False, False)
    f2.mainloop()


fifo()
