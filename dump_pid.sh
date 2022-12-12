cat /proc/$1/maps | grep -Fv ".so" | grep " 0 " | awk '{print $1}' | ( IFS="-"
while read a b; do
    dd if=/proc/$1/mem bs=$( getconf PAGESIZE ) iflag=skip_bytes,count_bytes \
       skip=$(( 0x$a )) count=$(( 0x$b - 0x$a )) of="$2/$1_mem_$a.bin"
done )