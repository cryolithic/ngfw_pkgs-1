#!/bin/dash

# This script sets the link media for a given NIC

if [ $# != 3 ]; then
    echo "USAGE: $0 <nic> <mode>"
    echo "\t mode: auto|10-full-duplex|10-half-duplex|100-full-duplex|100-half-duplex|1000-full-duplex"
    exit 0
fi

## ethtool fails a lot, this just hides those errors.
run_ethtool()
{
    ethtool $* 2> /dev/null
}

ETHTOOL=ethtool
ETHTOOL=run_ethtool

is_media_unset()
{
    local t_nic=$1
    local t_speed=$2
    local t_duplex=$3

    ## Check if auto-negotiation is on and the speed and duplex setting match
    ${ETHTOOL} ${t_nic} | awk -v IGNORECASE=1 "/auto-negotiation: off/ { matches++ }; /speed: ${t_speed}m/ { matches++ } ; /duplex: ${t_duplex}/ { matches++ } ;  END { if ( matches == 3 ) exit 1 }"
}

set_ethernet_media()
{
    local t_nic=$1
    local t_media=$2
    local t_eee=$3
    local t_speed
    local t_duplex

    if [ -z "${t_nic}" ]; then
        echo "$0 didn't specify nic."
        return 0
    fi

    if [ "${t_eee}" = "True" ] ; then
        t_eee=on
    else
        t_eee=off
    fi
    echo "setting eee to ${t_eee}"
    ethtool --show-eee ${t_nic} && ethtool --set-eee ${t_nic} eee ${t_eee}

    case "${t_media}" in
        "10-full-duplex")
            t_speed="10"
            t_duplex="full"
            ;;

        "10-half-duplex")
            t_speed="10"
            t_duplex="half"
            ;;

        "100-full-duplex")
            t_speed="100"
            t_duplex="full"
            ;;

        "100-half-duplex")
            t_speed="100"
            t_duplex="half"
            ;;

        "1000-full-duplex")
            t_speed="1000"
            t_duplex="full"
            ;;

        "1000-half-duplex")
            t_speed="1000"
            t_duplex="half"
            ;;

        "10000-full-duplex")
            t_speed="10000"
            t_duplex="full"
            ;;

        "10000-half-duplex")
            t_speed="10000"
            t_duplex="half"
            ;;

        "auto")
            ${ETHTOOL} ${t_nic} | grep -qi 'auto-negotiation: on'
            if [ ! $? -eq 0 ] ; then
                echo "Setting ${t_nic} to auto-negotiation."
                ${ETHTOOL} -s ${t_nic} autoneg on
            fi
            return 0
            ;;
        "*")
            echo "Unable to determine link speed from '${t_media}'"
            return 0
            ;;
    esac

    ## Not auto, have to set the speed manually (first check if it is already set)
    is_media_unset ${t_nic} ${t_speed} ${t_duplex} 
    if [ $? -eq 0 ] ; then
        echo "Setting ${t_nic} to ${t_speed} ${t_duplex}."
        ${ETHTOOL} -s ${t_nic} autoneg off speed ${t_speed} duplex ${t_duplex}
    fi
}

set_ethernet_media $*
