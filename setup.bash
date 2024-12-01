# oj tool
sudo apt install npm
npm install -g atcoder-cli
acc login
acc config default-task-choice all

# acc !! --break-system-packages maybe dangerous
sudo apt install python3-pip
python3 -m pip install online-judge-tools --break-system-packages
oj login https://atcoder.jp/

export KYOPRO_LIBRARY_ROOT=$(pwd)
echo "source ${KYOPRO_LIBRARY_ROOT}/.bashrc" >>  ~/.bashrc

