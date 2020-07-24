# Ubuntu and ROS Installtion for Raspberry Pi 3/4
- if you don't want to try you can go this link(need to create the link) to download the image. Follow step 3, 4, 5 and 7.

1. Download  and install Raspberry Pi imager for Windows or etcher.io from the link below.
    - Raspberry Pi imager for Windows link >> https://downloads.raspberrypi.org/imager/imager_1.4.exe
    - Raspberry Pi imager for other OS link >> https://www.raspberrypi.org/downloads/
    - etcher.io link >> https://www.balena.io/etcher/
2. Download Ubuntu image.
    - Ubuntu image link >> https://ubuntu.com/download/raspberry-pi
3. Erase SD Card
    - Open raspberry pi imager 
    - CLick on "Operating System"
    - Scroll down to "ERASE"   
    - Click on "SD Card" 
    - Select Deivce "eg. D:\" (Remember to plug in your SD Card)
    - CLick "WRITE"
    <img raspberrypi_ERASE.png>
4. Write/Burn the Ubuntu(18.04/20.04) image to Raspberry Pi SD card
    - Open raspberry pi imager 
    - CLick on "Operating System" 
    - Scroll down to "Use custom"  
    - Select the Ubuntu image downaloded 
    - Click on "SD Card" 
    - Select Deivce "eg. D:\" (Remember to format your SD first)
    - Click "WITRE"
    <img raspberrypi_Ubuntu.png>
5. Write/Burn the Ubuntu(18.04/20.04) image to Etcher.io (use this if you know what you doing)
    - Remember to format your SD first
    - Select the file Ubuntu image
    - Select the drive eg D:\
    - click flash
    <img Etcher_Ubuntu.png>
6. Using Oracle Virtualbox to copy and setup netplan to able SSH to raspberry pi
    - Copy 10-my-config.yaml to /media/"YOUR USERNAME"/writeable/etc/netplan
    - cd /media/"YOUR USERNAME"/writeable/etc/cloud/cloud.cfg.d/
    - sudo bash -c "echo 'network: {config: disabled}' > 99-disable-network-config.cfg"
    - cd /media/"YOUR USERNAME"/writeable/etc/netplan
    - sudo nano 10-my-config.yaml
    - edit and enter RACE or your WiFi SSID and Password 
    - write down or remember the part for ethernets: addresses:- 192.168.10.222 << you need the 222 for later part
    - eject SD Card in Virtualbox Ubuntu
    <link 10-my-config.yaml>
7. Running Ubuntu on raspberry pi
    - insert th SD card into the raspberry pi
    - plug in the LAN and USB power cables to raspberry pi while waiting for ubuntu to do it first boot
    - on your windows laptop right-click on your WiFi icon on your system tray
    - select open network and internet setting
    - scroll down to Advanced network setting >> click on change adapter options
    - look for Ethernet description that are "NOT Virtualbox, VPN or Hyper-V Virtual"
    - right-click that other Ethernet your found on step f >> click on properties
    - select on internet protocal version 4 (TCP/IPv4) >> click properties
    - check use the following IP Addresss
    - enter the as the following:
        i.      IP address      : 192.168.10.200
        ii.     Subnet mask     : 255.255.255.0
        iii.    Default gateway : 192.168.10.1
    - click ok
    - important to take note if you are using LAN at home do select back obation IP address automatically following step c to h
8. SSH to raspberry pi (focus using Windows Terminal)
    - open windows terminal(if you had install. Download it from Windows Store) if not download putty >> https://the.earth.li/~sgtatham/putty/latest/w64/putty.exe
    - for putty enter hostname : ubuntu@192.168.10.22x (x is depend the ip address set in 10-my-config.yaml)
    - for windows terminal enter : ubuntu@192.168.10.22x (x is depend the ip address set in 10-my-config.yaml)
    - enter yes for the public-key (once time setup)
    - enter default password: ubuntu
    - change password
        i.      enter current password  : ubuntu
        ii.     enter new password      : raspberry
        iii.    re-entry new passwor    : rassberry
    - you will exit after succefull password change
    - ssh in raspberry again with the method you like windows terminal or putty
9. you have installed ubuntu on raspberry pi
    - ls, cd, cp, mv, mkdir, rm, touch, cat, move and more command
    - check internet connection >> ping 8.8.8.8 if not ok need to troubleshoot 
    - update the system >> sudo apt update && apt upgrade
10. install bluetooth package via apt install or dpkg
    - need to edit syscfg.txt to enable bluetooth >> sudo nano /boot/firmware/syscfg.txt
    - change from include nobtcfg.txt to include btcfg.txt
    - install dependencies for bluetooth >> sudo apt install bluez
    - download the bluetooth package >> wget http://turul.canonical.com/ubuntu-ports/pool/multiverse/p/pi-bluetooth/pi-bluetooth_0.1.10ubuntu6_arm64.deb
    - install bluetooth package >> sudo dpkg -i pi-bluetooth_0.1.10ubuntu6_arm64.deb
    - reboot the system >> sudo reboot
11. install ROS
    - enter the following commands to add repo:
        i.      sudo add-apt-repository universe
        ii.     sudo add-apt-repository restricted
        iii.    sudo add-apt-repository multiverse
    - enter the following command to setup your sources.list:
        i.      sudo sh -c 'echo "deb http://packages.ros.org/ros/ubuntu $(lsb_release -sc) main" > /etc/apt/sources.list.d/ros-latest.list'
    - enter the following command to setup your keys:
        i.      sudo apt-key adv --keyserver 'hkp://keyserver.ubuntu.com:80' --recv-key C1CF6E31E6BADE8868B172B4F42ED6FBAB17C654
    - enter the following command for installation:
        i.      sudo apt update
        ii.     sudo apt install ros-melodic-ros-base
    - enter the following command for environment setup
        i.      echo "source /opt/ros/melodic/setup.bash" >> ~/.bashrc
        ii.     source ~/.bashrc
    - enter the following command for dependencies for building packages
        i.      sudo apt install python-rosdep
    - enter the following command for initialize rosdep
        i.      sudo rosdep init
        ii.     rosdep update
    - you have done installation of ROS for Raspberry pi







# VERY IMPORTANT 
pigpio need to install >> sudo apt-get install python3-distutils
ros python 2 need to install 
sudo apt install python-rosdep
ros python 3 need to install 
sudo apt install python3-pip python3-yaml
sudo pip3 install rospkg catkin_pkg
run using this once >> catkin_make -DPYTHON_EXECUTABLE=/usr/bin/python3

rosrun python/python3 error
/usr/bin/env: ‘python3\r’: No such file or directory
vi filename.py
:set ff=unix
:wq

how to kill process
ps 
 PID TTY          TIME CMD
 2445 pts/2    00:00:04 bash
 5761 pts/2    00:00:08 python3
 5792 pts/2    00:00:00 ps
check pid = 5761
sudo kill -9 5761

SD card Sandisk K is blue is test SD card to build all the images
