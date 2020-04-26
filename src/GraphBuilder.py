import matplotlib.pyplot as plt
import pandas as pd

df = pd.read_csv("/Users/dimasokolov/Desktop/MultiplicationData12.csv")

fig = plt.figure()
ax = plt.axes()
ax.plot('dalenna', 'gsa',data = df, label = "GSA", color='blue')
ax.plot('dalenna', 'Kara', data = df, label = "Karatsuba", color='purple')
ax.plot('dalenna', 'DiC', data = df, label = "Divide & Conquere", color='red')
plt.title("Time")
plt.xlabel("No. of Digits")
plt.ylabel("Seconds")
plt.legend()
plt.show()