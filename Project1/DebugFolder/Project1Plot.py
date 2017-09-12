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
    
with open("errors_10n.txt") as file:
    error_10n = file.readlines()

with open("errors_100n.txt") as file:
    error_100n = file.readlines()

with open("errors_1000n.txt") as file:
    error_1000n = file.readlines()
    
with open("errors_10e6n.txt") as file:
    error_10e6n = file.readlines()


#Extracting the max error in every errorlist. Not used to Python, sorry!
error_max = [0,0,0,0]
error_max[0] = max(error_10n)
error_max[1] = max(error_100n)
error_max[2] = max(error_1000n)
error_max[3] = max(error_10e6n)

#Initializing the steplength lists. Not used to Python, sorry!
h10 = [0]*12
h100 = [0]*102
h1000 = [0]*1002
for i in range(1,13):
        h10[i-1] = (1/13)*i
for i in range(1,103):
        h100[i-1] = (1/103)*i
for i in range(1,1003):
        h1000[i-1] = (1/1003)*i

#Plotting töpliz results vs exact results (n = 10,100,1000)
import matplotlib.pyplot as plt
fig1 = plt.figure(1)
h_10 = plt.plot(h10,topliz10, h10, exact10, h10, lu10)
h_10[0].set_ls('--')
h_10[2].set_ls('.-')
plt.title("Results with n = 10")
plt.legend([h_10[0],h_10[1],h_10[2]],["Thomas algorithm", "Exact values","LU decomp."])
plt.show()
fig1.savefig('results10n.png')

fig2 = plt.figure(2)
h_100 = plt.plot(h100,topliz100, h100, exact100,h100,lu100)
h_100[0].set_ls('--')
h_100[2].set_ls('.-')
plt.title("Results with n = 100")
plt.legend([h_100[0],h_100[1],h_100[2]],["Thomas algorithm", "Exact values","LU decomp."])
plt.show()
fig2.savefig('results100n.png')

fig3 = plt.figure(3)
h_1000 = plt.plot(h1000,topliz1000, h1000, exact1000)
h_1000[0].set_ls('--')
h_1000[2].set_ls('.-')
plt.title("Results with n = 1000")
plt.legend([h_1000[0],h_1000[1],h_1000[2]],["Thomas algorithm", "Exact values","LU decomp."])
plt.show()
fig3.savefig('results1000n.png')

#Plotting the errors
x = [-1,-2,-3, -6]
fig4 = plt.figure(4)
h_error = plt.scatter(x,error_max)
plt.title("Relative error vs. stepsize h")
plt.xlabel("stepsize h (log10)")
plt.ylabel("relative error (log10)")
ax = plt.gca()
ax.set_xticks([-3,-2,-1,-4,-5,-6])
plt.grid()
plt.show()
fig4.savefig('errors.png')