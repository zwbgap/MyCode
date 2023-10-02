# import numpy as np
# import matplotlib.pyplot as plt
import cv2
import sys
import pytesseract
if __name__ == '__main__':
    if len(sys.argv) < 2:
        print('Usage: python ocr_demo.py image.jpg')
        sys.exit(1)
    # 使用命令行参数
    imPath = sys.argv[1]
    config = ('-1 chi_sim --oem 1 --psm 3')
    im = cv2.imread(imPath, cv2.IMREAD_COLOR)

    # 进行识别，本质上是调用tesseract命令行工具
    text = pytesseract.image_to_string(im, config = config)

    # 打印结果
    print(text)