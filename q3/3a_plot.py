import matplotlib.pyplot as plt
import numpy as np

n = np.arange(10, 31)

f_n = 7 * n**2 + 7 * n + 5
c1 = 7
c2 = 19
c1_gn = c1 * n**2
c2_gn = c2 * n**2

plt.figure(figsize=(12, 7))

plt.plot(n, f_n, label='f(n) = 7n² + 7n + 5', color='blue', linewidth=3, marker='o', markersize=4)

plt.plot(n, c1_gn, label='c1 * g(n) = 7n²', linestyle='--', color='green', linewidth=2)

plt.plot(n, c2_gn, label='c2 * g(n) = 19n²', linestyle='--', color='red', linewidth=2)

plt.fill_between(n, c1_gn, c2_gn, color='gray', alpha=0.1, label='Theta Bounds Area')

plt.title('Visualization of Big Theta Complexity: f(n) = Θ(n²)', fontsize=14)
plt.xlabel('n (Input Size)', fontsize=12)
plt.ylabel('Growth Value', fontsize=12)

plt.xticks(np.arange(10, 31, 2))
plt.grid(True, linestyle=':', alpha=0.6)
plt.legend()

plt.tight_layout()
plt.show()
