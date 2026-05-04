import matplotlib.pyplot as plt
import numpy as np

n = np.arange(10, 31)

f_n = 3 * n**2 + 4 * n + 3
c = 10
cg_n = c * n

plt.figure(figsize=(10, 6))

plt.plot(n, f_n, label='f(n) = 3n² + 4n + 3', marker='o', color='royalblue', linewidth=2)

plt.plot(n, cg_n, label='c * g(n) = 10n', linestyle='--', marker='s', color='darkorange', linewidth=2)

plt.title('Visualization of f(n) = Ω(n)', fontsize=14)
plt.xlabel('n (Input Size)', fontsize=12)
plt.ylabel('Growth Value', fontsize=12)

plt.grid(True, linestyle=':', alpha=0.7)
plt.legend()

plt.tight_layout()
plt.show()
