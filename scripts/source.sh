#!/usr/local/bin/bash


mkdir -p ~/tmp/kbd
mv /mnt/c/Users/Steevee/Downloads/zsa_voyager_limelight_*.zip ~/tmp/kbd/limelight.zip

cd ~/tmp/kbd/

unzip -o ~/tmp/kbd/limelight.zip

mv ~/tmp/kbd/zsa_voyager_limelight_source ~/qmk_firmware/keyboards/zsa/voyager/keymaps/limelight_oryx

rm -rf ~/tmp/kbd
