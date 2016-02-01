# Get sample CMakeLists
echo Downloading CMakeLists.txt
mkdir test
wget http://pastebin.com/raw/QMCqrWG8 -O test/CMakeLists.txt

echo Obtaining Latest Release from github.com/google/googletest ..
RELEASE=$(curl -s https://api.github.com/repos/google/googletest/tags | grep -m 1 tarball_url | cut -d '"' -f4)

if [ ! -z "$RELEASE" -a "$RELEASE" != " " ]; then
	RELEASE="${RELEASE/api./}"
	RELEASE="${RELEASE/repos\//}"
	RELEASE="${RELEASE/tarball/archive}"
	RELEASE="$RELEASE.tar.gz"
else	# fallback onto version stable version 1.7.0
	RELEASE=https://github.com/google/googletest/archive/release-1.7.0.tar.gz
fi
wget -P test/ $RELEASE

# Unpack into test/ directory
echo Unpacking Google-Test...
tar -xf test/*.tar.gz -C test/
rm test/*.tar.gz

echo DONE: CMakeLists.txt and Google-Test source downloaded to directory test/