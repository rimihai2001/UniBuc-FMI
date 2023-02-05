import matplotlib.pyplot as plt
import numpy as np
# Calculeaza coordonatele (x, y) ale punctelor de pe o curba sin
# x - valori de la 0 la 3 * np.pi, luate din 0.1 in 0.1
x = [1,2,3]
y = np.sin(x)
# Ploteaza punctele
plt.plot(x, y)
# Adauga etichete pentru fiecare axa
plt.xlabel('x axis label')
plt.ylabel('y axis label')
# Adauga titlu
plt.title('Sine')
# Adauga legenda
plt.legend(['Sine'])

plt.plot(x, y, 'o')
# Afiseaza figura
plt.show()
