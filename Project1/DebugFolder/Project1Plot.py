# -*- coding: utf-8 -*-
"""
Created on Tue Sep  5 10:33:22 2017

@author: Ola

Plotting script for Project1 in FYS4150
"""

#Reading results from C++ code
with open("results_tridiagonal_10n.txt") as file:
    tridiagonal10 = file.readlines()
    
with open("results_tridiagonal_100n.txt") as file:
    tridiagonal100 = file.readlines()
    
with open("results_tridiagonal_1000n.txt") as file:
    tridiagonal1000 = file.readlines()

with open("results_topliz_10n.txt") as file:
    topliz10 = file.readlines()

with open("results_topliz_100n.txt") as file:
    topliz100 = file.readlines()

with open("results_topliz_1000n.txt") as file:
    topliz1000 = file.readlines()
    
with open("results_exact_10n.txt") as file:
    exact10 = file.readlines()

with open("results_exact_100n.txt") as file:
    exact100 = file.readlines()

with open("results_exact_1000n.txt") as file:
    exact1000 = file.readlines()
    
#with open("results_error_10n.txt") as file:
 #   error10 = file.readlines()

#with open("results_error_100n.txt") as file:
  #  error10 = file.readlines()

#with open("results_error_1000n.txt") as file:
 #   error10 = file.readlines()

#Initializing the steplength vectors. Not used to Python, sorry!
h10 = [0]*10
h100 = [0]*100
h1000 = [0]*1000
for i in range(1,11):
        h10[i-1] = (1/11)*i
for i in range(1,101):
        h100[i-1] = (1/101)*i
for i in range(1,1001):
        h1000[i-1] = (1/1001)*i


#Plotting all the results
import matplotlib.pyplot as plt
fig1 = plt.figure(1)
h_10 = plt.plot(h10,tridiagonal10, h10, exact10)
h_10[1].set_ls('--')
plt.title("Results with n = 10")
plt.show()
fig1.savefig('results10n.png')

fig2 = plt.figure(2)
h_100 = plt.plot(h100,tridiagonal100, h100, exact100)
h_100[1].set_ls('--')
plt.title("Results with n = 100")
plt.show()
fig2.savefig('results100n.png')

fig3 = plt.figure(3)
h_1000 = plt.plot(h1000,tridiagonal1000, h1000, exact1000)
h_1000[1].set_ls('--')
plt.title("Results with n = 1000")
plt.show()
fig3.savefig('results1000n.png')