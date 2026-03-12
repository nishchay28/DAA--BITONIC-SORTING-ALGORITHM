import numpy as np
import matplotlib.pyplot as plt
from matplotlib.widgets import Slider

# Initial value
max_n = 50

# Create figure
fig, ax = plt.subplots()
plt.subplots_adjust(bottom=0.25)

# Function to compute complexity
def compute(n):
    return n * (np.log2(n)**2)

# Initial data
n = np.arange(1, max_n)
y = compute(n)

# Plot initial graph
(line,) = ax.plot(n, y, linewidth=2)
ax.set_xlabel("Input Size (n)")
ax.set_ylabel("Operations")
ax.set_title("Bitonic Sort Complexity O(n log² n)")

# Slider
ax_slider = plt.axes([0.2, 0.1, 0.65, 0.03])
slider = Slider(ax_slider, "Input Size", 10, 500, valinit=max_n)

# Update graph when slider moves
def update(val):
    n = np.arange(1, int(slider.val))
    y = compute(n)
    line.set_xdata(n)
    line.set_ydata(y)
    ax.relim()
    ax.autoscale_view()
    fig.canvas.draw_idle()

slider.on_changed(update)

plt.show()