import tkinter as tk
import matplotlib
import matplotlib.pyplot as plt
import numpy as np

def abs ():
    t =  np.arange(0.0, 2.0)
    s = 1 + np

    fig, ax = plt.subplots()
    ax.plot(t,s)

    ax.set(title = 'Absolute')
    ax.grid()

    fig.savefig("exponential.png")
    plt.show()

def log():
    t = np.arange(0.01, 20.0, 0.01)
    plt.subplot(223)
    plt.loglog(t,20*np.exp(-t/10.0),basex = 2)
    plt.grid (True)
    plt.title ('Logarithmic base 2')
    plt.show()

def exponential ():
    x_min = 0
    x_max = 10.0

    x = np.arange(x_min, x_max, .01)
    y = np.exp(x)

    plt.plot(x, y)

    plt.xlim(x_min, x_max)
    plt.ylim(np.exp(x_min), np.exp(x_max))

    plt.yscale('log')

    plt.grid(True, which="both", linestyle='--')

    plt.title("Exponential")
    plt.show

def mainMenu():
    top = tk.Tk()
    B = tk.Button(top, text="Absolute", command= abs())
    C = tk.Button(top, text="Logaritmic", command = log() )
    D = tk.Button(top, text = "Exponential", command = exponential())
    B.pack()
    C.pack()
    D.pack()
    top.mainloop()


mainMenu()



