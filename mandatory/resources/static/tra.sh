for file in *.xpm; do
	new_name=`echo $file | cut -d '.' -f 1`
	new_name="$new_name".png

	echo $new_name
convert $file $new_name
done
