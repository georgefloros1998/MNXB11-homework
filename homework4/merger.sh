#!/bin/bash

# File name: merger.sh

# Description:
# This script merges 2 CSV datasets into one
# The merged datasets should be previously cleaned
# Suggested cleaning method: smhicleaner.sh

# Memorize script name
MERGER_SCRIPTNAME='basename $0'

###### Functions ########

usage(){
   echo "----"
	echo -e "  To call this script please use"
	echo -e "   $0 '<path-to-first-datafile>' '<path-to-second-datafile>'"
	echo "----"
}

##### Functions END #####

# T1 Get the two parameters from the command line
INPUT_FILE1=$1
INPUT_FILE2=$2

#T2 Input parameter validation:
if [[ "x$INPUT_FILE1" == 'x' ]] || [[ "x$INPUT_FILE2" == 'x' ]]; then
   echo "Missing input file parameter, exiting" 1>&2
   usage
   exit 1
fi

# T3 Extract filename:
ORIGINALFILENAME1="original_$(basename "$INPUT_FILE1")"
ORIGINALFILENAME2="original_$(basename "$INPUT_FILE2")"
MERGED_DATAFILE="merged_${ORIGINALFILENAME1}_${ORIGINALFILENAME2}.csv"
# The final name is TOO big, and with too many ".csv" in it

# T4 Analyze the input parameter and copy:
# T4.1 If $INPUT_FILE1 and $INPUT_FILE2 not empty
if [[ "x$INPUT_FILE1" != "x" ]] && [[ "x$INPUT_FILE2" != "x" ]]; then
   # T4.2 check if the each file is a directory, it should not be!
   if [[ -d $INPUT_FILE1 ]] || [[ -d $INPUT_FILE2 ]]; then
      echo -e "This script requires data files and not directories, exiting..." 1>&2
      exit 1
   fi
   # T4.3 Copy the files in the current directory 
   echo "Copying input file $INPUT_FILE1 to $ORIGINALFILENAME1"
   cp -a $INPUT_FILE1 $ORIGINALFILENAME1
   # Capture copy errors
   COPY_OUTCOME1=$?
   echo "Copying input file $INPUT_FILE2 to $ORIGINALFILENAME2"
   cp -a $INPUT_FILE2 $ORIGINALFILENAME2
   # Capture copy errors
   COPY_OUTCOME2=$?
fi

# T5 Check that the input file has been copied with no errors:
if [[ $COPY_OUTCOME1 != 0 ]] || [[ $COPY_OUTCOME2 != 0 ]]; then
   echo "Error downloading or copying file, check filename or command syntax. Exiting...." 1>&2
   usage
   exit 1
fi

# T6 Merge the two files into one
cat "$ORIGINALFILENAME1" "$ORIGINALFILENAME2" | sort -u > "$MERGED_DATAFILE"
# Can also use the INPUT_FILE if I don't want the copies
echo "Files merged successfully into $MERGED_DATAFILE"