#! /usr/local/bin/python3

from PIL import Image

K_DIGITILS = "0123456789"

art = None
i = 0
for d in K_DIGITILS:
    sub = Image.open(d + '.png');
    if art is None:
        art = Image.new("RGBA", (sub.size[0] * len(K_DIGITILS), sub.size[1]))
    art.paste(sub, (i * sub.size[0], 0))
    i = i + 1

art.save('combine.png')
