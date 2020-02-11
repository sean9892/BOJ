from PIL import Image

im=Image.open("SOKOBAN3.png")
rgb=im.convert('RGB')

for x in range(47):
    s=""
    for y in range(53):
        tup=rgb.getpixel((y,x))
        if tup==(0,0,0):
            s+="#"
        elif tup==(255,255,255):
            s+="."
        elif tup==(163,73,164):
            s+="S"
        elif tup==(63,72,204):
            s+="B"
        else:
            s+="P"
    print(s)
