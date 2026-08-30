import matplotlib.pyplot as plt

# 矩形的坐标
rects = [
    [-15, 0, 5, 10],
    [-5, 8, 20, 25],
    [15, -4, 24, 14],
    [0, -6, 16, 4],
    [2, 15, 10, 22],
    [30, 10, 36, 20],
    [34, 0, 40, 16]
]

# 创建一个新的图形和轴
fig, ax = plt.subplots()

# 绘制矩形
for rect in rects:
    xmin, ymin, xmax, ymax = rect
    ax.add_patch(plt.Rectangle((xmin, ymin), xmax - xmin, ymax - ymin, fill=False))

# 设置坐标轴范围
x_values = [x for rect in rects for x in rect[::2]]
y_values = [y for rect in rects for y in rect[1::2]]
ax.set_xlim(min(x_values) - 5, max(x_values) + 5)
ax.set_ylim(min(y_values) - 5, max(y_values) + 5)

# 添加坐标标签
for rect in rects:
    xmin, ymin, xmax, ymax = rect
    ax.text(xmin, ymin, f'({xmin}, {ymin})', fontsize=8)
    ax.text(xmax, ymax, f'({xmax}, {ymax})', fontsize=8)

# 添加坐标轴标签
ax.set_xlabel('X-axis')
ax.set_ylabel('Y-axis')

# 显示图形
plt.grid(True)
plt.show()