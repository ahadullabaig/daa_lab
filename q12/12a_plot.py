import matplotlib.pyplot as plt
import numpy as np

n = np.arange(10, 31)

f_n = 3 * n**2 + 4 * n + 3
c_gn = 10 * n

plt.figure(figsize=(10, 6))

plt.plot(n, f_n, label='f(n) = 3n² + 4n + 3', marker='o', color='royalblue', linewidth=2)
plt.plot(n, c_gn, label='c * g(n) = 10n', linestyle='--', marker='s', color='darkorange', linewidth=2)
plt.fill_between(n, f_n, c_gn, color='royalblue', alpha=0.1, label='f(n) >= c*g(n)')

plt.grid(True, linestyle=':', alpha=0.7)
plt.legend()
plt.title('Big Omega Visualization: f(n) = Ω(n)')
plt.xlabel('n (Input Size)')
plt.ylabel('Growth Value')

plt.tight_layout()
plt.show()
