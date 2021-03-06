# Minerva: a fast and flexible system for deep learning

## Latest News

* Minerva had migrated to [dmlc](https://github.com/dmlc), where you could find many awesome machine learning repositories!
* Minerva now evolves to use cudnn_v2. Please download and use the new [library](https://developer.nvidia.com/cuDNN).

## Overview

Minerva is a fast and flexible tool for deep learning. It provides NDarray programming interface, just like Numpy. Python bindings and C++ bindings are both available. The resulting code can be run on CPU or GPU. Multi-GPU support is very easy. Please refer to the examples to see how multi-GPU setting is used.Minerva is a fast and flexible tool for deep learning. It provides NDarray programming interface, just like Numpy. Python bindings and C++ bindings are both available. The resulting code can be run on CPU or GPU. Multi-GPU support is very easy. Please refer to the examples to see how multi-GPU setting is used.

## Features

* N-D array programming interface (similar to numpy)
* Easy interaction with NumPy
* Multi-GPU, multi-CPU support

## Performance

We will keep updating the latest performance we could achieve in this section.

### Training speed

| Training speed <br> (images/second) | AlexNet | VGGNet | GoogLeNet |
|:------------------------------:|:-------:|:------:|:---------:|
| 1 card | 189.63 | 14.37 | 82.47 |
| 2 cards| 371.01 | 29.58 | 160.53 |
| 4 cards| 632.09 | 50.26 | 309.27 |
* The performance is measured on a machine with 4 GTX Titan cards.
* On each card, we load minibatch size of 256, 24, 120 for AlexNet, VGGNet and GoogLeNet respectively. Therefore, the total minibatch size will increase as the number of cards grows (for example, training AlexNet on 4 cards will use 1024 minibatch size).

### An end-to-end training

We also provide some end-to-end training codes in `owl` package, which could load Caffe's model file and perform training. Note that, Minerva is *not* the same tool as Caffe. We are not focusing on this part of logic. In fact, we implement these just to play with the Minerva's powerful and flexible programming interface (we could implement a Caffe-like network trainer in around 700~800 lines of python codes). Here is the training error with time compared with Caffe. Note that Minerva could finish GoogleNet training in less than four days with four GPU cards.

![Error curve](https://cloud.githubusercontent.com/assets/4057701/6857873/454c44b2-d3e0-11e4-9010-9e62c6c94027.jpg)

## License and support

Minerva is provided in the Apache V2 open source license.

You can use the "issues" tab in github to report bugs. For non-bug issues, please send up an email at minerva-support@googlegroups.com.

## Wiki

For more information on how to install, use or contribute to Minerva, please visit our wiki page: https://github.com/minerva-developers/minerva/wiki

