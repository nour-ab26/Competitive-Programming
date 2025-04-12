cd /mnt/c/Users/ZeroDayOutplay/Documents/Projects/Food-Delivery-App

echo "[+] Please enter the commit message:"
read commit_msg

echo "[+] ZDO repo"
git add .
git commit -m "$commit_msg"
git push

cd /mnt/c/Users/ZeroDayOutplay/Documents/Projects/Food-Delivery-App-Deployable

echo "[+] Bikech0 repo"
git add .
git commit -m "$commit_msg"
git push