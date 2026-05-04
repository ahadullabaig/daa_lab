import matplotlib.pyplot as plt

n_values = list(range(10, 31))

c = 8

fn = [7*n + 5 for n in n_values]
cgn = [c * n for n in n_values]

plt.plot(n_values, fn, label='f(n) = 7n + 5', marker='o', color='blue')
plt.plot(n_values, cgn, label='c*g(n) = 8n (c=8)', marker='s', linestyle='--', color='green')

plt.axvline(x=5, color='red', linestyle=':', label='n0 = 5')

plt.xlabel('n')
plt.ylabel('Value')
plt.title('f(n) = O(n) : f(n) vs c*g(n)')
plt.legend()
plt.grid(True)
plt.show()
