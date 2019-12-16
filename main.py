import imageio
import matplotlib.pyplot as plt
import tkinter as tk
from tkinter.simpledialog import askstring
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
from matplotlib.figure import Figure
from tkinter import *
import pytest

def pytest_report_header(config):
    return "project dependencies in testing phrase: Pillow, iamgeio, matplotlib and picture.jpg"


pic = None
application_window = tk.Tk()
def picAnaR(pic):
    root = tk.Tk()
    plt.title('R channel')
    plt.ylabel('Height {}'.format(pic.shape[0]))
    plt.xlabel('Width {}'.format(pic.shape[1]))
    plt.imshow(pic[:, :, 0])
    plt.show()
    canvas = FigureCanvasTkAgg(Figure(), master=root)
    canvas.get_tk_widget().pack(side="top", fill="both", expand=1)
    canvas._tkcanvas.pack(side="top", fill="both", expand=1)

    root.mainloop()
def picAnaG(pic):
    root = tk.Tk()
    plt.title('G channel')
    plt.ylabel('Height {}'.format(pic.shape[0]))
    plt.xlabel('Width {}'.format(pic.shape[1]))
    plt.imshow(pic[:, :, 1])
    plt.show()
    canvas = FigureCanvasTkAgg(Figure(), master=root)
    canvas.get_tk_widget().pack(side="top", fill="both", expand=1)
    canvas._tkcanvas.pack(side="top", fill="both", expand=1)

    root.mainloop()
def picAnaB(pic):
    root = tk.Tk()
    plt.title('B channel')
    plt.ylabel('Height {}'.format(pic.shape[0]))
    plt.xlabel('Width {}'.format(pic.shape[1]))
    plt.imshow(pic[:, :, 2])
    plt.show()
    canvas = FigureCanvasTkAgg(Figure(), master=root)
    canvas.get_tk_widget().pack(side="top", fill="both", expand=1)
    canvas._tkcanvas.pack(side="top", fill="both", expand=1)

    root.mainloop()
def tkinterMenu(pic):
    root = Tk().title("Main Menu")
    menubar = Menu(root)
    filemenu = Menu(menubar, tearoff=0)
    filemenu.add_command(label="Red Channel", command=picAnaR(pic))
    filemenu.add_command(label="Green Channel", command=picAnaG(pic))
    filemenu.add_command(label="Blue Channel", command=picAnaB(pic))

    filemenu.add_separator()

    filemenu.add_command(label="Exit", command=root.quit())
    menubar.add_cascade(label = "Functions", menu =  filemenu)
    root.config(menu=menubar)
    root.mainloop()

def mainMenu():

    importPic = askstring("Input", "Please declare the name of the picture", parent=application_window)
    if importPic is not None:
        pic = imageio.imread(importPic)
        plt.figure(figsize=(15, 15))
        plt.imshow(pic)

        if pic.size == 150954:
            pass


        tkinterMenu(pic)


        return pic
    else:
        print("Please give valid file id")


mainMenu()