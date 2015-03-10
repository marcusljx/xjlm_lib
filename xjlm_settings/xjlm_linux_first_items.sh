#### Shell Script file for initial set-up on Linux

# PPA additions
sudo add-apt-repository ppa:webupd8team/sublime-text-3




# Update
sudo apt-get update


# Package Installations
sudo apt-get install git g++ sublime-text-installer xorg-dev build-essential libmagick++-dev libgnome-keyring-dev


# Gnome Keyring set-up on non-GNOME environments
sudo apt-get install libpam-gnome-keyring
	# Add to file : [sudo subl /etc/pam.d/common-pamkeyring]
	#										auth optional pam_gnome_keyring.so try_first_pass
	#										session optional pam_gnome_keyring.so auto_start
	#	Add to file : [sudo subl /etc/pam.d/kdm]
	#										@include common-pamkeyring




# Setting up gnome-keyring for GIT authentication storage
cd /usr/share/doc/git/contrib/credential/gnome-keyring
sudo make
sudo rm git-credential-gnome-keyring.o
sudo mv git-credential-gnome-keyring /usr/bin
git config --global credential.helper gnome-keyring

# Changing Terminal environment
	# enabling history-based auto-complete
	# in bashrc file (either [~/.bashrc] or [/etc/bash.bashrc]),
	# append the following lines:
		# 		bind '"\e[A": history-search-backward'
		#			bind '"\e[B": history-search-forward'
