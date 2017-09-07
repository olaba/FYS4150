# -*- coding: utf-8 -*-
"""
Created on Tue Sep  5 22:05:56 2017

@author: Ola
"""



#initialize a error_max and error lists
errormax = [0]*3
error10 = [0]*10
error100 = [0]*100
error1000 = [0]*1000
exact10float = [0]*10
topliz10float = [0]*10
exact100float = [0]*100
topliz100float = [0]*100
temp = [0]*100
temp2 = [0]*100
exact1000float = [0]*1000
topliz1000float = [0]*1000


#Makes the lists from string to float, and calculate error
for k in range(0,10):
    exact10float[k] = float(exact10[k])
    topliz10float[k] = float(topliz10[k])
    error10[k] = log10(abs((exact10float[k] - topliz10float[k])/exact10float[k]))
    
    
for j in range(0,100):
    exact100float[j] = float(exact100[j])
    topliz100float[j] = float(topliz100[j])
    temp[j] = abs(exact100float[j] - topliz100float[j])
    temp2[j] = (temp[j])/(exact100float[j])
    
for j in range(0,100):   
    error100[k] = log10(temp2[j])
    
    
for m in range(0,888): #stops at 888, since log10 has it's limitations :)
    exact1000float[m] = float(exact1000[m])
    topliz1000float[m] = float(topliz1000[m])
    error1000[m] = log10(abs((exact1000float[m] - topliz1000float[m])/exact1000float[m]))

#extracts the biggest error in the list of errors.
for k in range(1,10):
    if(error10[k] > error10[k-1]):
        errormax[0] = error10[k]

for k in range(1,100):
    if(error100[k] < error100[k-1]): #used less than since the error work only at one place :S
        errormax[1] = error100[k]

for k in range(1,10):
    if(error1000[k] > error1000[k-1]):
        errormax[2] = error1000[k]