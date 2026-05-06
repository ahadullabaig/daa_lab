import matplotlib.pyplot as plt
import numpy as np

n = np.arange(10, 31)

fn = 3 * n**2 + 4 * n + 3
cgn = 10 * n

plt.figure(figsize=(10, 6))

plt.plot(n, fn, label='f(n) = 3n² + 4n + 3', marker='o', color='royalblue', linewidth=2)
plt.plot(n, cgn, label='c * g(n) = 10n', linestyle='--', marker='s', color='darkorange', linewidth=2)

plt.grid(True, linestyle=':', alpha=0.7)
plt.legend()

plt.tight_layout()
plt.show()
