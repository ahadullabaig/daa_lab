import matplotlib.pyplot as plt
import numpy as np

n = np.arange(10, 31)

f_n = 5 * n + 5
c = 5
cg_n = c * n

plt.figure(figsize=(10, 6))

plt.plot(n, f_n, label='f(n) = 5n + 5', marker='o', color='blue', linewidth=2)

plt.plot(n, cg_n, label='c * g(n) = 5n', linestyle='--', marker='s', color='orange', linewidth=2)

plt.fill_between(n, f_n, cg_n, color='blue', alpha=0.1, label='f(n) >= c*g(n)')

plt.title('Big Omega Visualization: f(n) = Ω(n)', fontsize=14)
plt.xlabel('n (Input Size)', fontsize=12)
plt.ylabel('Growth Value', fontsize=12)

plt.xticks(np.arange(10, 31, 2))

plt.grid(True, linestyle=':', alpha=0.7)
plt.legend()

plt.tight_layout()
plt.show()
