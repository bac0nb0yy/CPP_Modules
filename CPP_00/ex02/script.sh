NC='\033[0m'

BLACK='\033[0;30m'
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
BLUE='\033[0;34m'
PURPLE='\033[0;35m'
CYAN='\033[0;36m'
WHITE='\033[0;37m'

if [ $# -eq 1 ]; then
	if [ $1 = "delete" ]; then
		rm -rf *.log
		exit 0
	fi
fi

ORIGINAL="19920104_091532.log"

# Maybe need to change the link according to the intra if it is not working

curl -s -o $ORIGINAL https://cdn.intra.42.fr/document/document/22781/$ORIGINAL

echo "${RED}Original file downloaded: ${PWD}/${ORIGINAL}${NC}"
echo "${GREEN}Now compiling the bank program${NC}"

./GlobalBanksters >/tmp/file1
NEW=$(dd skip=1 bs=1 count=15 if=/tmp/file1 2>/dev/null).log
mv /tmp/file1 $NEW

echo "${PURPLE}Now diffing the original file with the new one${NC}"

cut -b18- $NEW >trimmed1
cut -b18- $ORIGINAL >trimmed2

if ! diff -q trimmed1 trimmed2 >/dev/null; then
	echo "${RED}Something went wrong${NC}"
else
	echo "${GREEN}All good!${NC}"
fi

rm -rf trimmed1 trimmed2
