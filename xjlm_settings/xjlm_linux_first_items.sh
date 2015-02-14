#### Shell Script file for initial set-up on Linux

# PPA additions
sudo add-apt-repository ppa:webupd8team/sublime-text-3


# Update
sudo apt-get update


# Package Installations
sudo apt-get install git g++ sublime-text-installer xorg-dev build-essential libmagick++-dev libgnome-keyring-dev


# Setting up gnome-keyring for GIT authentication storage
cd /usr/share/doc/git/contrib/credential/gnome-keyring
sudo make
git config --global credential.helper /usr/share/doc/git/contrib/credential/gnome-keyring/git-credential-gnome-keyring