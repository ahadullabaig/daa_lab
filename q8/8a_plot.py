import matplotlib.pyplot as plt
import numpy as np

n = np.arange(10, 31)

f_n = 6 * n**2 + 2 * n + 2
c = 10
cg_n = c * n**2

plt.figure(figsize=(10, 6))

plt.plot(n, f_n, label='f(n) = 6n² + 2n + 2', marker='o', color='blue', linewidth=2)
plt.plot(n, cg_n, label='c * g(n) = 10n²', linestyle='--', marker='s', color='red', linewidth=2)

plt.title('Big O Visualization: f(n) = O(n²)', fontsize=14)
plt.xlabel('n (Input Size)', fontsize=12)
plt.ylabel('Growth Value', fontsize=12)

plt.xticks(np.arange(10, 31, 2))
plt.grid(True, linestyle=':', alpha=0.7)
plt.legend()

plt.tight_layout()
plt.show()
