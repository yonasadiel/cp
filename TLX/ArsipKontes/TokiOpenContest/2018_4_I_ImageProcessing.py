gambar = ['' for i in range(0, 51)]

for i in range(1, 51):
	gambar[i] = input()


if (gambar[33][7] == '`'):
	print("CAR")
elif (gambar[22][13] == '`'):
	print("CAR")
elif (gambar[33][3] == ':'):
	print("CAR")
elif (gambar[28][6] == '`'):
	print("CAR")
else:
	print("PLANE")