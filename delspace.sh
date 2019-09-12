PRE_IFS=$IFS
IFS=$'\n'
function foo(){
        for file in `ls $1`       
        do
			filename=$1"/"$file
			mv ${filename} `echo "${filename}" | sed s/[[:space:]]//g` 
			
            if [ -d $1"/"$file ]  
            then
                foo $1"/"$file
            fi
        done
    }   
foo '.'
IFS=$PRE_IFS