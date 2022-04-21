import PyRectangle

x0, y0, x1, y1 = 1, 2, 3, 4
rect = PyRectangle.PyRectangle(x0, y0, x1, y1)
msg = b"hello_world"
print("python msg address", id(msg))
print(rect.get_area(msg))
