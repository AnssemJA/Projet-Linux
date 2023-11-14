from tkinter import *
import subprocess


f1=1
f11=1
f2=1
def closef11():
    global f11
    f11.destroy()
def closef2():
    global f2
    f2.destroy()

def page2():
    closef1()
    openf11()
def page2():
    closef11()
    openf2()
def socket():
    
    subprocess.call(["make"])
    
def clfifo():
    result=subprocess.run(["./cl"],stdout=subprocess.PIPE,text=True)
    return result.stdout
def serfifo():
    console=subprocess.run(["./ser"],stdout=subprocess.PIPE,text=True)
    return console.stdout
def signaux():
     subprocess.call(["make"])
   
def closef1():
    global f1
    f1.destroy()

def page2():
    closef1()
    openf11()

def openf1():# page d'acceuil
    
    global f1
    f1= Tk()
    f1.title("Acceuil") #nom de l'interface 
    f1.geometry("1000x500")#size de l'interface 
    f1.configure(bg = "#fdfefe")#background blanc
    canvas = Canvas(
        f1,
        bg = "#fdfefe",
        height = 500,
        width = 900,
        bd = 0,
        highlightthickness = 0,
        relief = "ridge")
    canvas.place(x =0, y = 0)

    background_img = PhotoImage(file = f"b1.png")
    background = canvas.create_image(
        500, 260,
        image=background_img)

    

    img0 = PhotoImage(file = f"menu.png")
    b0 = Button(
        image = img0,
        borderwidth = 0,
        highlightthickness = 0,
        command = page2,
        relief = "flat",
        bg="#ffffff")

    b0.place(
        x = 500, y = 320,
        width = 200,
        height = 70)

    f1.resizable(False, False)
    f1.mainloop()


def openf11():
    global f11
    
    f11= Tk()
    f11.title("Acceuil")
    f11.geometry("1000x500")
    f11.configure(bg = "#ffffff")
    canvas = Canvas(
        f11,
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

    

    img0 = PhotoImage(file = f"signaux.png")
    b0 = Button(
        image = img0,
        borderwidth = 0,
        highlightthickness = 0,
        command =signaux,
        relief = "flat",
        bg="#ffffff")

    b0.place(
        x = 350, y = 200,
        width = 300,
        height = 100)

    img1 = PhotoImage(file = f"socket.png")
    b1 = Button(
        image = img1,
        borderwidth = 0,
        highlightthickness = 0,
        command = socket,
        relief = "flat",
        bg="#ffffff")

    b1.place(
        x = 350, y = 300,
        width = 300,
        height = 100)

    f11.resizable(False, False)
    f11.mainloop()
"""def clientfifo():
    closef11
    global f2
    
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
    result=clfifo()
    canvas.create_text(500, 260,text=result,fill="#FFFFFF",font=("Comfortaa-Regular",int(18.0)))

    f2.resizable(False, False)
    f2.mainloop()"""


openf1()
