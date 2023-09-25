for ((i=0; i<4; i++)); do
	git rev-parse --verify HEAD
	git checkout -q HEAD~1
done
git rev-parse --verify HEAD
git checkout -q master
