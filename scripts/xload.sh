sudo kextunload -b com.kadirgecit.AirportItlwm
sudo chown -R root:wheel ./../Build/Products/Debug/AirportItlwm.kext
sudo kextutil -v 6 ./../Build/Products/Debug/AirportItlwm.kext
