import os
from wand.image import Image

def ConvertImage(file, format, out):
    print('convert {} \n to {}'.format(file, out))
    with Image(filename=file) as img:
            img.convert(format=format)
            img.save(filename=out)

def ConvertImageDir(dir, format='tga', filter='.png'):
    files = os.listdir(dir)
    outdir = os.path.join(dir, 'convert')
    if not os.path.exists(outdir):
        os.mkdir(outdir, True)
    for file in files:
        if file.endswith(filter):
            out = os.path.splitext(file)[0] + '.' + format
            ConvertImage(os.path.join(dir, file), format, os.path.join(outdir, out))


def CopyImageH(image, count = 1, out=None):
    if out is None:
        out = image
    with Image(filename=image) as img:
        merged = Image(width=img.width * count, height=img.height)
        for i in range(count):
            merged.composite(img, img.width * i, 0)
        merged.save(filename=out)

def CopyImageV(image, count = 1, out=None):
    if out is None:
        out = image
    with Image(filename=image) as img:
        merged = Image(width=img.width, height=img.height * count)
        for i in range(count):
            merged.composite(img, 0, img.height * i)
        merged.save(filename=out)

image_dir = 'G:/image/'
ConvertImageDir(image_dir, 'tga', '.jpg')
ConvertImageDir(image_dir, 'tga', '.png')
#CopyImageH(os.path.join(image_dir, 'bottom_base.tga'), 4)

