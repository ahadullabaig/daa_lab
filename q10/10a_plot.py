import matplotlib.pyplot as plt
import numpy as np

n = np.arange(10, 31)

f_n = 5 * n**2 + 6 * n + 3
c1 = 5
c2 = 14
c1_gn = c1 * n**2
c2_gn = c2 * n**2

plt.figure(figsize=(12, 7))

plt.plot(n, f_n, label='f(n) = 5n² + 6n + 3', color='blue', linewidth=3, marker='o', markersize=4)
plt.plot(n, c1_gn, label='c1 * g(n) = 5n²', linestyle='--', color='green', linewidth=2)
plt.plot(n, c2_gn, label='c2 * g(n) = 14n²', linestyle='--', color='red', linewidth=2)

plt.fill_between(n, c1_gn, c2_gn, color='gray', alpha=0.1, label='Theta Bounds Area')

plt.title('Visualization of Big Theta Complexity: f(n) = Θ(n²)', fontsize=14)
plt.xlabel('n (Input Size)', fontsize=12)
plt.ylabel('Growth Value', fontsize=12)

plt.xticks(np.arange(10, 31, 2))
plt.grid(True, linestyle=':', alpha=0.6)
plt.legend()

plt.tight_layout()
plt.show()
